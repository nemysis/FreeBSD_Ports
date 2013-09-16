# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shirk
PORTVERSION=	0.5
CATEGORIES=	irc
MASTER_SITES=	GITHUB
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Modular IRC bot based on the Twisted framework

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	frank001
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	wigglytuff
GH_COMMIT=	1f21873

USE_PYTHON=	yes
USE_TWISTED=	framework words

PORTDOCS=	README.md

SUB_FILES=	${PORTNAME} \
		pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|python2.7|${PYTHON_CMD}|' \
		${WRKSRC}/shirk.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in *.py *.pyc *.pyo
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${d} ${DATADIR})
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "plugconf plugs" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/conf-example.json ${DATADIR}

	@for file in conf.json ; do \
		if [ ! -e "${DATADIR}/$$file" ]; then \
			${ECHO_MSG} "   Installing local configuration file: ${DATADIR}/$$file"; \
			${CP} -a ${DATADIR}/conf-example.json ${DATADIR}/$$file; \
				else \
					${ECHO_MSG} "Preserving local configuration file: ${DATADIR}/$$file"; \
		fi; \
	done

	@${CHMOD} 644 ${DATADIR}/conf.json

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
