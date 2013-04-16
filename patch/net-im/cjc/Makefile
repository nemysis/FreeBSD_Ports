# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD: head/net-im/cjc/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	cjc
PORTVERSION=	1.2.1
CATEGORIES=	net-im python
MASTER_SITES=	http://cloud.github.com/downloads/Jajcus/cjc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Console Jabber Client

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=0:${PORTSDIR}/net-im/py-pyxmpp

USE_PYTHON=	2.6+

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog README TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	manual.html

.include <bsd.port.options.mk>

post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s|/usr/bin/python|${PYTHON_CMD}|"
	@${REINPLACE_CMD} -e \
		"s|prefix=.*|prefix=${PREFIX}| ; \
		 /pkg_docdir/s|^|#|g ; \
		 s|INSTALL=.*|INSTALL=${INSTALL}| ; \
		 s|INSTALL_DATA=.*|INSTALL_DATA=${INSTALL_DATA}| ; \
		 s|INSTALL_DIR=.*|INSTALL_DIR=${MKDIR}|g" ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
