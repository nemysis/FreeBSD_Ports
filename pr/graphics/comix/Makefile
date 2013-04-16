# $FreeBSD: head/graphics/comix/Makefile 309763 2012-12-31 17:03:21Z mezz $
#   $MCom: ports-stable/graphics/comix/Makefile,v 1.1 2006/10/21 18:39:46 mezz Exp $

PORTNAME=	comix
PORTVERSION=	4.0.4
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GTK2 comic book viewer for .cbz, .cbr, and .cbt files

LICENSE=	GPLv2

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

USE_GNOME=	desktopfileutils pygtk2
WANT_GNOME=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog README
MAN1=		comix.1

OPTIONS_DEFINE=	THUMBNAILS NLS
THUMBNAILS_DESC=Enable graphic thumbnails

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:Mnautilus2} || ${PORT_OPTIONS:MTHUMBNAILS}
USE_GNOME+=	gnomehier gconf2
MAN1+=		comicthumb.1
GCONF_SCHEMAS=	comicbook.schemas
PLIST_SUB+=	THUMBNAILS:=""
THUMBNAILS_ENABLED=yes
.else
PLIST_SUB+=	THUMBNAILS:="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name \*.gz | ${XARGS} ${GUNZIP_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' \
	-e 's|1.gz|1|g' \
	-e 's|$$(gconftool-2 --get-default-source)|$${GCONF_CONFIG_SOURCE}|' \
		${WRKSRC}/install.py
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/for lang in TRANSLATIONS/,/'LC_MESSAGES')/s/^/#/' ${WRKSRC}/install.py
.endif
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/src
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/src

do-install:
.if ${PORT_OPTIONS:MTHUMBNAILS}
	${MKDIR} ${PREFIX}/share/mime/packages
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install --dir ${PREFIX})
	${MKDIR} ${PREFIX}/etc/gconf/schemas
	${INSTALL_DATA} ${WRKSRC}/mime/comicbook.schemas \
		${PREFIX}/etc/gconf/schemas/
.else
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install \
			--dir ${PREFIX} --no-mime)
.endif
	${INSTALL_DATA} ${WRKSRC}/src/comix.pyc ${DATADIR}/src

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@-update-desktop-database -q

.include <bsd.port.post.mk>
