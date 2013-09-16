# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/pycadia/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	pycadia
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/} \
		SF/nemysisfreebsdp/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Home to vector gaming, Python style

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	pygtk2 libgnomeui
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGELOG README TODO gravity.txt

DESKTOP_ENTRIES="Pycadia" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

SUB_FILES=	${PORTNAME}.sh

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "glade pixmaps sounds *.py *.ico *.cfg" ${DATADIR})
	@(cd ${DATADIR} && ${CHMOD} 555 ${PORTNAME}.py spacewarpy.py vektoroids.py)
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${DATADIR}
	${LN} -sf ${DATADIR}/pixmaps/pysteroids.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
