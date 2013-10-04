# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cocos2d
PORTVERSION=	0.5.5
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	los-cocos
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Framework for building 2D games, demos, and other applications

LICENSE=	BSD GPLv2 CCbyNCSA2
LICENSE_COMB=	multi
LICENSE_NAME_CCbyNCSA2=	Attribution-NonCommercial-ShareAlike 2.0 Unported
LICENSE_FILE=	${WRKSRC}/LICENSE ${WRKSRC}/LICENSE.python_interpreter ${WRKSRC}/LICENSE.euclid
LICENSE_FILE_CCbyNCSA2=	${WRKSRC}/LICENSE.grossini
LICENSE_PERMS_CCbyNCSA2=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyglet>=0:${PORTSDIR}/graphics/py-pyglet \
		avbin>=0:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_GL=		yes
USE_SDL=	mixer
USE_PYTHON=	2.7
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGELOG README

DATADIR=	${PREFIX}${PYTHON_SITELIBDIR:S|${LOCALBASE}||}/${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

OPTIONS_DEFINE=	BENCHMARKS DOCS SAMPLES TEST TOOLS UTEST
OPTIONS_DEFAULT=	BENCHMARKS SAMPLES

BENCHMARKS_DESC=	Install some benchmark programs
SAMPLES_DESC=		Install sample programs
TEST_DESC=		Install test
TOOLS_DESC=		Install developer tools
UTEST_DESC=		Install unittest

OPTIONS_SUB=	yes

UTEST_RUN_DEPENDS=	py.test>=0:${PORTSDIR}/devel/py-pytest

.include <bsd.port.options.mk>

PLIST_SUB+=	PYVER=${PYTHON_VER}
PLIST_SUB+=	MAJORVER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -i '' '/install_require/,/dependency_links/s/^/#/' \
		${WRKSRC}/setup.py

regression-test: build
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test)

do-build:
	@(cd ${WRKSRC}/cocos && ${PYTHON_CMD} -m compileall .)
	@(cd ${WRKSRC}/cocos && ${PYTHON_CMD} -O -m compileall .)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/EGG-INFO
	@(cd ${WRKSRC}/cocos2d.egg-info && ${CP} * ${STAGEDIR}${DATADIR}/EGG-INFO)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} cocos ${STAGEDIR}${DATADIR})

.if ${PORT_OPTIONS:MBENCHMARKS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} benchmarks ${STAGEDIR}${DATADIR})
.endif

.if ${PORT_OPTIONS:MSAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${STAGEDIR}${DATADIR})
.endif

.if ${PORT_OPTIONS:MTEST}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} test ${STAGEDIR}${DATADIR})
.endif

.if ${PORT_OPTIONS:MTOOLS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} tools ${STAGEDIR}${DATADIR})
.endif
.if ${PORT_OPTIONS:MUTEST}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} utest ${STAGEDIR}${DATADIR})
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
