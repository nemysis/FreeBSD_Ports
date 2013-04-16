# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD: head/multimedia/quark/Makefile 315433 2013-03-28 03:28:30Z eadler $

PORTNAME=	quark
PORTVERSION=	3.24
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://hsgg.github.com/quark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio player, for geeks, by geeks

LICENSE=	GPLv2

LIB_DEPENDS=	xine:${PORTSDIR}/multimedia/libxine

USES=		pathfix
USE_GNOME=	gnomeprefix gnomevfs2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS README
GCONF_SCHEMAS=	quark.schemas strange-quark.schemas

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/charm-quark/charm-quark
	@${REINPLACE_CMD} -e 's|CFLAGS="-g |CFLAGS="$$CFLAGS |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/strange-quark/Makefile.in ${WRKSRC}/quark/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
