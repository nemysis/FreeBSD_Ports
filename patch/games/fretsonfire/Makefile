# New ports collection makefile for:	fretsonfire
# Date created:		2006-09-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD: head/games/fretsonfire/Makefile 315097 2013-03-24 05:09:32Z acm $
#

PORTNAME=	fretsonfire
PORTVERSION=	1.3.110
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/f/F/g:S/o/O/}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game of musical skill and fast fingers

RUN_DEPENDS=	${PYNUMPY} \
		${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:${PORTSDIR}/games/fretsonfire-data

USE_PYTHON=	yes
USE_DOS2UNIX=	*.txt
NO_BUILD=	yes

DATADIR=	share/${PORTNAME}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude 'data'
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}"
WRKSRC=		"${WRKDIR}/Frets on Fire-${PORTVERSION}"

USE_GETTEXT=	yes

FOF_DIR=	${PREFIX}/lib/${PORTNAME}

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	PSYCO
PSYCO_DESC=	Enable Psyco support (Only for i386)

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPSYCO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psyco>=0:${PORTSDIR}/devel/py-psyco
.endif

do-install:
	${MKDIR} ${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}
	@cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py)" -exec ${INSTALL_DATA} "{}" "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \;

	${MKDIR} ${FOF_DIR}/data
	${LN} -s ${LOCALBASE}/${DATADIR}/* ${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:S/f/F/g:S/o/O/} ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
