# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/cutemaze/Makefile 303823 2012-09-07 20:08:28Z ak $

PORTNAME=	cutemaze
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
Uses=		desktop-file-utils
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	ChangeLog README

.include <bsd.port.options.mk>

post-extract:
	@${RM} -f ${WRKSRC}/icons/oxygen/LGPL

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-install:
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} oxygen ${PREFIX}/share/icons)
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
