# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtknetcat
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	SF/lxde/GtkNetCat%20%28GUI%20for%20netcat%29/GtkNetCat%20${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GTK GUI for netcat

LICENSE=	GPLv3

USES=		gmake
USE_GNOME=	gtk20 intlhack
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|Icon=|Icon=${PORTNAME}|' \
		${WRKSRC}/${PORTNAME}.desktop

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
