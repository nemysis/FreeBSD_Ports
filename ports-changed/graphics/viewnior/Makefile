# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/graphics/viewnior/Makefile 316464 2013-04-24 18:10:30Z ak $

PORTNAME=	viewnior
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		pkgconfig
USE_GNOME=	glib20 gtk20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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
