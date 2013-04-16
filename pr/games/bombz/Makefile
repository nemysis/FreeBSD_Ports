# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	bombz
PORTVERSION=	0.2
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple 2D puzzle game with bombs

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/Bombz

USE_ZIP=	yes
USE_SDL=	sdl image mixer
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	ChangeLog readme.txt

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' '/words = name.split()/,/self.name = name/s/^/#/' \
		${WRKSRC}/bombz/joy.py

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

.for d in bombz levels pngs sounds FreeSans.ttf
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
