# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/games/gtktetcolor/Makefile 315433 2013-03-28 03:28:30Z eadler $

PORTNAME=	gtktetcolor
DISTVERSION=	0.6.5pre3
CATEGORIES=	games gnome
MASTER_SITES=	ftp://canopus.iacp.dvo.ru/pub/Games/gtktetcolor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game for GNOME that resembles well-known Tetris and Columns

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USES=		pathfix
USE_PKGCONFIG=	build
USE_GNOME=	desktopfileutils gnomeprefix intlhack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|games\.games|games:games|g' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@-update-desktop-database -q

.include <bsd.port.mk>
