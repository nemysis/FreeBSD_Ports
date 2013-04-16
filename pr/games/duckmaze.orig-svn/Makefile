# New Ports collection makefile for:	duckmaze
# Date created:        2012-04-15
# Whom:                nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	duckmaze
PORTVERSION=	0.3r34
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game about a duck that is in a maze

LICENSE=	GPLv2

FETCH_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USE_PYTHON=	yes
NO_BUILD=	yes

SVN_REV=	34

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	TODO.txt index.html

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
# Fix path to python interpreter
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/*.py ${WRKSRC}/mopelib/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak mopelib/*py.bak)

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc images levels mopelib music sounds" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/duckmazerc.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/version ${DATADIR}

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/doc/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.  endfor
.endif

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} \
		https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME} ${PORTNAME}
	${TAR} jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
