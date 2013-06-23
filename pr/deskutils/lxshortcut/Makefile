# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	lxshortcut
PORTVERSION=	0.1.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/lxde/LXShortcut%20%28edit%20app%20shortcut%29/LXShortcut%20${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Small utility used to edit easily application shortcuts

LICENSE=	GPLv3

USES=		pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

SUB_FILES=	${PORTNAME}-start

DESKTOP_ENTRIES="LXShortcut" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}-start" "Settings;GTK;DesktopSettings;" true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -i '' '/g_thread_init/,/gdk_threads_init/d' ${WRKSRC}/src/lxshortcut.c

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-start ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
