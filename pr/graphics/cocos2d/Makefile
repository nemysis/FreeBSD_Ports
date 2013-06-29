# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	cocos2d
PORTVERSION=	0.5.5
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	los-cocos
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Framework for building 2D games, demos, and other applications

LICENSE=	BSD GPLv2 CCbyNCSA2
LICENSE_COMB=	multi
LICENSE_NAME_CCbyNCSA2=	Attribution-NonCommercial-ShareAlike 2.0 Unported
LICENSE_FILE=	${WRKSRC}/LICENSE ${WRKSRC}/LICENSE.python_interpreter ${WRKSRC}/LICENSE.euclid
LICENSE_FILE_CCbyNCSA2=	${WRKSRC}/LICENSE.grossini
LICENSE_PERMS_CCbyNCSA2=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyglet-devel>=0:${PORTSDIR}/graphics/py-pyglet-devel \
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

OPTIONS_DEFINE=	DOCS BENCHMARKS SAMPLES TEST TOOLS UTEST
OPTIONS_DEFAULT=	BENCHMARKS SAMPLES
BENCHMARKS_DESC=	Install some benchmark programs
SAMPLES_DESC=		Install sample programs
TEST_DESC=		Install test
TOOLS_DESC=		Install developer tools
UTEST_DESC=		Install unittest

.include <bsd.port.options.mk>

PLIST_SUB+=	PYVER=${PYTHON_VER}
PLIST_SUB+=	MAJORVER=${PORTVERSION}

.if ${PORT_OPTIONS:MBENCHMARKS}
PLIST_SUB+=	BENCHMARKS=""
.else
PLIST_SUB+=	BENCHMARKS="@comment "
.endif

.if ${PORT_OPTIONS:MSAMPLES}
PLIST_SUB+=	SAMPLES=""
.else
PLIST_SUB+=	SAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	TOOLS=""
.else
PLIST_SUB+=	TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MTEST}
PLIST_SUB+=	TEST=""
.else
PLIST_SUB+=	TEST="@comment "
.endif

.if ${PORT_OPTIONS:MUTEST}
RUN_DEPENDS+=	py.test>=0:${PORTSDIR}/devel/py-pytest
PLIST_SUB+=	UTEST=""
.else
PLIST_SUB+=	UTEST="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i '' '/install_require/,/dependency_links/s/^/#/' ${WRKSRC}/setup.py

regression-test: build
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test)

do-build:
	@(cd ${WRKSRC}/cocos && ${PYTHON_CMD} -m compileall .)
	@(cd ${WRKSRC}/cocos && ${PYTHON_CMD} -O -m compileall .)

do-install:
	@${MKDIR} ${DATADIR}/EGG-INFO
	@(cd ${WRKSRC}/cocos2d.egg-info && ${CP} * ${DATADIR}/EGG-INFO)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} cocos ${DATADIR})

.if ${PORT_OPTIONS:MBENCHMARKS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} benchmarks ${DATADIR})
.endif

.if ${PORT_OPTIONS:MSAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${DATADIR})
.endif

.if ${PORT_OPTIONS:MTEST}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} test ${DATADIR})
.endif

.if ${PORT_OPTIONS:MTOOLS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} tools ${DATADIR})
.endif
.if ${PORT_OPTIONS:MUTEST}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} utest ${DATADIR})
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR})
.endif

.include <bsd.port.mk>
