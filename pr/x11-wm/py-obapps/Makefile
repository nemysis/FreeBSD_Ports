# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	obapps
PORTVERSION=	0.1.7
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Graphical editor for Openbox application settings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

USE_PYTHON=	yes
USE_WX=		2.8+
WX_COMPS=	python:run
USE_PYDISTUTILS=yes

PLIST_FILES=	bin/${PORTNAME} \
		%%PYTHON_SITELIBDIR%%/obaxutils.py \
		%%PYTHON_SITELIBDIR%%/obaxutils.pyc \
		%%PYTHON_SITELIBDIR%%/obaxutils.pyo \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

DESKTOP_ENTRIES="OBApps" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Settings;" false

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
