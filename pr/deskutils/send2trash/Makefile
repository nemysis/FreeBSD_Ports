# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	send2trash
PORTVERSION=	1.2.0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Send2Trash-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Small package that sends files to the Trash

LICENSE=	BSD

USE_PYTHON=	2.7
USE_PYDISTUTILS=easy_install

CONFLICTS=	send2trash3k

PORTDOCS=	CHANGES README

.include <bsd.port.options.mk>

SUB_LIST=	PYVER=${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e "s|name='Send2Trash'|name='send2trash'|" \
		${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
