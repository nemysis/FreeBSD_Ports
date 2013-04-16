# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD: head/graphics/boxer/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	boxer
PORTVERSION=	0.3.8
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	box
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GUI for Box the figure description language

LICENSE=	GPLv3

RUN_DEPENDS=	box:${PORTSDIR}/graphics/box

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTDOCS=	ChangeLog

DESKTOP_ENTRIES="Boxer" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Application;Graphics;" false

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
