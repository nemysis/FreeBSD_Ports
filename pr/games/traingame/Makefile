# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	traingame
PORTVERSION=	0.2.2
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/:game \
		SF/nemysisfreebsdp/:icons
DISTFILES=	TrainGame-${DISTVERSION}${EXTRACT_SUFX}:game \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game about Trains

LICENSE=	GPLv3

BUILD_DEPENDS+=	${CMAKE_BIN}:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		xerces-c:${PORTSDIR}/textproc/xerces-c3 \
		boost_filesystem:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/TrainGame-${PORTVERSION}

USES=		cmake
CMAKE_VERBOSE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image
USE_GL=		glew
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.6+

PORTDOCS=	README.txt model_notes.txt models.gnuplot

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME} \
		pkg-install \
		pkg-message

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/TrainGame ${DATADIR}/${PORTNAME}

.for d in buildings engines fonts images layouts maps schemas trees waggons
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	@${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@-update-desktop-database

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
