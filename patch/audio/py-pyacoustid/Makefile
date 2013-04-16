# Created by: Mark Felder <feld@feld.me>
# $FreeBSD: head/audio/py-pyacoustid/Makefile 312275 2013-02-15 06:01:13Z miwi $

PORTNAME=	pyacoustid
PORTVERSION=	0.7
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@feld.me
COMMENT=	Bindings for Chromaprint acoustic fingerprinting and the Acoustid API

LICENSE=	MIT

LIB_DEPENDS=	chromaprint:${PORTSDIR}/audio/chromaprint
BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-distribute

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/acoustid.py \
		%%PYTHON_SITELIBDIR%%/chromaprint.py

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
	@(cd ${WRKSRC}/build/lib && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR})

.include <bsd.port.mk>
