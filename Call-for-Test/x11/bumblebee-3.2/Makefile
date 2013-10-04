# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	bumblebee
PORTVERSION=	3.2
CATEGORIES=	x11
MASTER_SITES=	GH
#MASTER_SITES=	https://github.com/downloads/Bumblebee-Project/Bumblebee/
# https://github.com/downloads/Bumblebee-Project/Bumblebee/bumblebee-3.0.1.tar.gz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Bumblebee daemon for Optimus hybrid graphics chipsets

LICENSE=	GPLv3

BUILD_DEPENDS=	 help2man:${PORTSDIR}/misc/help2man

USE_GITHUB=	yes
GH_ACCOUNT=	Bumblebee-Project
GH_PROJECT=	Bumblebee
GH_TAGNAME=	master
GH_COMMIT=	8d69a05

#USE_GITHUB=	yes
#GH_ACCOUNT=	seanbruno
#GH_PROJECT=	fbsd-bumblebee
#GH_TAGNAME=	master
#GH_COMMIT=	48a1491
#8d69a05

USE_GNOME=	glib20
USE_XORG=	x11
USES=		pkgconfig

USE_AUTOTOOLS=	autoconf:env aclocal:env
GNU_CONFIGURE=	yes
#CONFIGURE_ENV+=	libbsd_LIBS=/usr/lib
#USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool
#USE_AUTOTOOLS=	automake autoconf libtool
#AUTOMAKE_ARGS=	--add-missing --force
# automake:env
#ACLOCAL_ARGS=	-fi
#AUTOCONF_ARGS=	-fi
#AUTOMAKE_ARGS=	--add-missing
#USE_GMAKE=	yes
#ALL_TARGET=	# empty
#MAKE_JOBS_SAFE=	yes

#CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib

#PORTDOCS=	RELEASE_NOTES_3_0_1

#INSTALLS_ICONS=	yes
#ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

#DESKTOP_ENTRIES="Bomb-her-man" "${COMMENT}" "${PORTNAME}" \
#		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

#OPTIONS_DEFINE=	NLS

#.include <bsd.port.options.mk>

pre-configure:
#	@(cd ${WRKSRC} && ${AUTORECONF} -fi)
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -fi)

#post-patch:
#	@${REINPLACE_CMD} -e 's|linux/limits.h|sys/syslimits.h|' ${WRKSRC}/src/bbrun.c
#	@${REINPLACE_CMD} -i '' '/if not rox.confirm/,/sys.exit/s/^/#/' ${WRKSRC}/AppRun
#	@${REINPLACE_CMD} -i '' '/if not rox.confirm/,/sys.exit/s/^/#/' ${WRKSRC}/AppRun

#.if ${PORT_OPTIONS:MNLS}
#USE_GETTEXT=	yes
#PLIST_SUB+=	NLS=""
#.else
#CONFIGURE_ARGS+=	--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

#pre-configure:
#	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

#.if ${PORT_OPTIONS:MNLS}
#	@${REINPLACE_CMD} -e 's|itlocaledir = $$(prefix)/$$(DATADIRNAME)/locale|itlocaledir = $$(prefix)/share/locale|' \
#		${WRKSRC}/po/Makefile.in.in
#.endif

#post-install:
#.for s in ${ICON_SIZES}
#	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
#	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
#		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
#.endfor
#	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

#.if ${PORT_OPTIONS:MDOCS}
#	${MKDIR} ${DOCSDIR}
#	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
#.endif

.include <bsd.port.mk>
