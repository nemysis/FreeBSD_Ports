# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/graphics/viewnior/Makefile 305213 2012-10-03 17:46:09Z madpilot $

PORTNAME=	viewnior
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes

MAN1=		viewnior.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)/locale|$$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
