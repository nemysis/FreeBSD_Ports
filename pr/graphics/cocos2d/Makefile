# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	cocos2d
PORTVERSION=	0.5.5
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	los-cocos

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Framework for building 2D games, demos, and other applications

LICENSE=	BSD GPLv2 CCbyNCSA2
LICENSE_COMB=	multi
LICENSE_NAME_CCbyNCSA2=	Attribution-NonCommercial-ShareAlike 2.0 Unported
LICENSE_FILE=	${WRKSRC}/LICENSE ${WRKSRC}/LICENSE.python_interpreter ${WRKSRC}/LICENSE.euclid
LICENSE_FILE_CCbyNCSA2=	${WRKSRC}/LICENSE.grossini
LICENSE_PERMS_CCbyNCSA2=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet-devel>=0:${PORTSDIR}/graphics/py-pyglet-devel \
		${PYNUMPY} \
		avbin>=7:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
USE_PYTHON=	2.7
USE_PYDISTUTILS=	yes
USE_WX=		yes
WX_COMPS=	python:lib
NO_BUILD=	yes

PORTDOCS=	CHANGELOG README

DATADIR=	${PYTHON_SITELIBDIR}/${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.options.mk>

post-install:
.for d in benchmarks dist samples test tools utest
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

# Dynamically generate PLIST
.for d in EGG-INFO cocos benchmarks dist samples test tools utest
	@${FIND} ${DATADIR}/${d}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/${d}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}
.endfor
	@${ECHO} "@unexec ${RMDIR} \"${DATADIR}\" 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
