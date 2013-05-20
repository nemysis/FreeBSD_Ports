# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	fpm2
PORTVERSION=	0.79
CATEGORIES=	security
MASTER_SITES=	http://als.regnet.cz/fpm2/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Program that allows you to securely store the passwords

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		freetype:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_GNOME=	atk gnomeprefix gnomelibs gdkpixbuf2 gtk20 libxml2
INSTALLS_OMF=	yes
USE_XORG=	pixman x11
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PREFIX}/share/pixmaps/${PORTNAME}/logo.png|' \
		-e 's|^Categories=.*|Categories=GTK;Utility;System;|' \
		${WRKSRC}/data/${PORTNAME}.desktop.in

post-patch:
	@${REINPLACE_CMD} -E -e "s@encrypt\(@bfishencrypt\(@g" ${WRKSRC}/src/blowfish.c

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|USE_NLS=yes|USE_NLS=no|' ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
