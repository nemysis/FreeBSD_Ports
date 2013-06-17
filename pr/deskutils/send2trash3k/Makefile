# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	send2trash3k
PORTVERSION=	1.2.0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Send2Trash3k-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Small package that sends files to the Trash

LICENSE=	BSD

USE_PYTHON=	3.1-3.2
USE_PYDISTUTILS=easy_install

PORTDOCS=	CHANGES README

.include <bsd.port.options.mk>

PLIST_SUB=	PYVER=${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e "s|name='Send2Trash3k'|name='send2trash3k'|" \
		${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
