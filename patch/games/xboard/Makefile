# Created by: xaa@stack.nl
# $FreeBSD: head/games/xboard/Makefile 318248 2013-05-15 16:58:53Z johans $

PORTNAME=	xboard
PORTVERSION=	4.7.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

LICENSE=	GPLv3

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	CRAFTY FAIRYMAX GNUCHESS KNIGHTCAP PHALANX
OPTIONS_DEFAULT=
CRAFTY_DESC=	Install crafty engine
FAIRYMAX_DESC=	Install fairymax engine
GNUCHESS_DESC=	Install GnuChess engine
KNIGHTCAP_DESC=	Install KnightCap engine
PHALANX_DESC=	Install phalanx engine

USES=		desktop-file-utils pkgconfig shared-mime-info
USE_XORG=	xt xpm xaw
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		MKDIR_P="${MKDIR}"

MAN6=		xboard.6

INFO=		xboard

DATADIR=	${PREFIX}/share/games/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRAFTY}
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

.if ${PORT_OPTIONS:MFAIRYMAX}
RUN_DEPENDS+=	fairymax:${PORTSDIR}/games/fairymax
.endif

.if ${PORT_OPTIONS:MGNUCHESS}
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if ${PORT_OPTIONS:MKNIGHTCAP}
RUN_DEPENDS+=	KnightCap:${PORTSDIR}/games/KnightCap
.endif

.if ${PORT_OPTIONS:MPHALANX}
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/fairymax/gnuchessx/' ${WRKSRC}/xboard.conf.in
	@${REINPLACE_CMD} -e '/^#include..malloc.h/d' \
		${WRKSRC}/engineoutput.c ${WRKSRC}/uci.c
	@${REINPLACE_CMD} -e 's:INSTALL.*sysconfdir):&/$$$$files.dist:' \
		${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cmail ${PREFIX}/bin/
	@${CP} -pn ${PREFIX}/etc/xboard.conf.dist ${PREFIX}/etc/xboard.conf

.include <bsd.port.post.mk>
