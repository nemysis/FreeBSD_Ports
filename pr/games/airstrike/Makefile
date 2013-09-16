# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	airstrike
PORTVERSION=	c7
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/airstrike/ \
		http://offload2.icculus.org:9090/airstrike/
DISTNAME=	${PORTNAME}-pre6a-src_freebsd_and_v${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	2d biplane dogfight game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-pre6a-src

USE_SDL=	image mixer sdl
USES=		desktop-file-utils
USE_GMAKE=	yes
ALL_TARGET=
INSTALLS_ICONS=	yes

MAN6=		${PORTNAME}.6

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	1.0-features 33fps.out BUGS TODO WHISHLIST *.txt \
		collisions.tm design.dia design.pdf fun.ps

SUB_FILES=	${PORTNAME} \
		pkg-message

DESKTOP_ENTRIES="Airstrike" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS += -DLINUX|#CFLAGS += -DLINUX|' ${WRKSRC}/src/Makefile
	@${FIND} ${WRKSRC} -name '*.c' -or -name '*.h' | ${XARGS} \
		${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

do-build:
	@(cd ${WRKSRC} ; ${GMAKE} airstrike-sound)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data airstrikerc" ${DATADIR})
	${LN} -sf ${WRKSRC}/data/balloon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	${INSTALL_MAN} ${WRKSRC}/doc/${MAN6} ${MAN6PREFIX}/man/man6

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
