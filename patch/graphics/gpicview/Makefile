# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD: head/graphics/gpicview/Makefile 316850 2013-04-29 22:27:05Z bapt $

PORTNAME=	gpicview
PORTVERSION=	0.2.3
CATEGORIES=	graphics
MASTER_SITES=	SF/lxde/GPicView%20%28image%20Viewer%29/GpicView%20${PORTVERSION}/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Simple and Fast Image Viewer for X

LICENSE=	GPLv2

USES=		desktop-file-utils
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

PORTDOCS=	AUTHORS

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
