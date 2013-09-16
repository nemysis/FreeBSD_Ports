# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD: head/games/4stattack/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	4stattack
PORTVERSION=	2.1.4
PORTREVISION=	8
CATEGORIES=	games python
MASTER_SITES=	SF/forcedattack/4stAttack/${PORTVERSION}
DISTNAME=	4stAttack-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Connect four stones in a straight line

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

USE_PYTHON=	yes

PORTDOCS=	README.txt changelog.txt credits.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 22x22 32x32 48x48 64x64

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="4st Attack" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/themeresizer.sh
	@for i in `${FIND} ${WRKSRC}/kde -name \forcedattack2.*`; do \
		${MV} $$i `echo $$i | ${SED} -e 's/forcedattack2/${PORTNAME}/'`; done
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/

.for d in data gui players
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.for p in *.py *.pyc *.pyo
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${p} ${DATADIR})
.endfor

.for d in  *.ini ini.txt *.ttf *.sh version
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/kde/icons/${s}/${PORTNAME}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${LN} -sf ${DOCSDIR}/credits.txt ${DATADIR}

.include <bsd.port.mk>
