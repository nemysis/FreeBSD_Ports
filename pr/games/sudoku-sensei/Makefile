# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	sudoku-sensei
PORTVERSION=	02.00
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-for-linux/Source%20and%20exe%20files%20for%20linux%2C%20ver.%202.00/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-src-${DISTVERSION:S/./-/}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-src-${DISTVERSION:S/./-/}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Enjoy playing with Sudoku boards designed by yourself

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/SudokuSenseiSources

USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats \
		corelib gui

MAKE_JOBS_SAFE=	yes

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="Sudoku Sensei" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/SudokuSensei ${DATADIR}

.for d in board doc images language saves system
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.for d in SudokuSensei.rc license.txt
	@(cd ${WRKSRC} && ${CP} -a ${d} ${DATADIR})
.endfor
# Fix Permission that user can write in saves and system directories
	@(cd ${DATADIR} && ${CHMOD} -R 775 saves system)

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
