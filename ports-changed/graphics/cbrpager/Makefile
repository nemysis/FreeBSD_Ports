# Created by: ijliao
# $FreeBSD: head/graphics/cbrpager/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	cbrpager
PORTVERSION=	0.9.22
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Viewer for cbr (comic book archive) files

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GNOME=	libgnomeui
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	CONTRIBUTORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS

DESKTOP_ENTRIES="cbrPager" "Comic book viewer" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Viewer;GNOME;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
PLIST_FILES+=	share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fr/LC_MESSAGES/${PORTNAME}.mo
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|src po|src|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
