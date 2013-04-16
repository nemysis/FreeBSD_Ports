# Created by:	nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	bouncy
PORTVERSION=	r6
CATEGORIES=	games python
MASTER_SITES=	http://media.pyweek.org/dl/3/bouncy/
DISTFILES=	${PORTNAME}-post-${DISTVERSION}.tgz \
		toon-shaded.jpg-thumb.png
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-post-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	You are a hungry rabbit. Eat food to complete the level

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl

WRKSRC=		${WRKDIR}/${PORTNAME}-post-${DISTVERSION}

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	README.txt

INSTALLS_ICONS=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Bouncy the Hungry Rabbit" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	SHADER
SHADER_DESC=	Hardware shader support

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MSHADER}
	@${REINPLACE_CMD} -i '' '/#try/,/#    print/s/#//' ${WRKSRC}/objects.py
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data pyglyph" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/toon-shaded.jpg-thumb.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
