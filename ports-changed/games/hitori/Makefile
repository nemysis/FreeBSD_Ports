# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/hitori/Makefile 316464 2013-04-24 18:10:30Z ak $

PORTNAME=	hitori
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Logic game similar to Sudoku

LICENSE=	GPLv3 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=	${WRKSRC}/COPYING-DOCS
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	xml2po:${PORTSDIR}/textproc/gnome-doc-utils \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_XZ=		yes
USES=		gmake desktop-file-utils
USE_GNOME=	glib20 gtk30
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog MAINTAINERS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)/locale|$$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
