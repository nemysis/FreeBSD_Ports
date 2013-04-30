# $FreeBSD: head/x11-wm/obmenu/Makefile 305526 2012-10-08 10:38:47Z dougb $

PORTNAME=	obmenu
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Menu manager for Openbox supporting both static and pipe menus

LICENSE=	GPLv2

USE_GNOME=		pygtk2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	obMenu

PORTDOCS=	README

SUB_FILES=	pkg-install \
		pkg-message

DESKTOP_ENTRIES="Obmenu" "Menu manager for Openbox" ${PORTNAME} \
		"${PORTNAME}" "Settings;" false

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${LN} -sf ${DATADIR}/mnu48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
