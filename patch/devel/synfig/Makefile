# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD: head/devel/synfig/Makefile 310553 2013-01-17 16:05:38Z swills $

PORTNAME=	synfig
DISTVERSION=	0.63.05
PORTREVISION=	4
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Vector based 2D animation package

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		MagickWand:${PORTSDIR}/graphics/ImageMagick \
		jpeg:${PORTSDIR}/graphics/jpeg \
		mng:${PORTSDIR}/graphics/libmng \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		dv:${PORTSDIR}/multimedia/libdv \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26

USE_GNOME=	gnomehack glib20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' -e \
		's|el_GR|el|g' -e \
		's|no_NO|no|g' -e \
		's|pl_PL|pl|g' -e \
		's|sk_SK|sk|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/url_fclose/s|&formatc|formatc|g' \
		${WRKSRC}/src/modules/mod_libavcodec/trgt_av.cpp

# FIX LC_MESSAGES
	${MV} ${WRKSRC}/po/no_NO.gmo ${WRKSRC}/po/no.gmo
	${MV} ${WRKSRC}/po/pl_PL.gmo ${WRKSRC}/po/pl.gmo
	${MV} ${WRKSRC}/po/sk_SK.gmo ${WRKSRC}/po/sk.gmo
	${MV} ${WRKSRC}/po/el_GR.gmo ${WRKSRC}/po/el.gmo

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
