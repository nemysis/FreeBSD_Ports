# Created by: bremner@unb.ca
# $FreeBSD: head/graphics/ipe/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	ipe
PORTVERSION=	7.1.4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}7/${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Extensible drawing editor

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_LDCONFIG=	yes
USE_LUA=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_QT4=	gui qt3support qmake_build moc_build uic_build rcc_build
MAN1=		ipe.1 ipe6upgrade.1 ipeextract.1 iperender.1 ipetoipe.1 ipescript.1

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(shell pkg-config --cflags $$(LUA_PACKAGE))|-I$$(LUA_INCDIR)|' \
		-e 's|$$(shell pkg-config --libs $$(LUA_PACKAGE))|-L$$(LUA_LIBDIR) -llua|' \
		-e 's|#IPEPREFIX  := /usr/local|IPEPREFIX  := $${PREFIX}|' \
		-e 's|share/ipe/$$(IPEVERS)/doc|share/doc/ipe/$$(IPEVERS)|' \
		-e 's|share/man/man1|man/man1|' \
			${WRKSRC}/config.mak

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DIR) $$(INSTALL_ROOT)$$(IPEDOCDIR)||' \
		-e 's|$$(INSTALL_FILES) ../../build/doc/* $$(INSTALL_ROOT)$$(IPEDOCDIR)||' \
			${WRKSRC}/ipe/Makefile
#.if defined(NOPORTDOCS)
#EXTRA_PATCHES+=	${FILESDIR}/extrapatch-ipe__Makefile
.endif

PLIST_SUB+=	VERSION="${DISTVERSION}"

post-install:
	cd ${WRKSRC}/../fontmaps && ${MKDIR} ${DATADIR}/${DISTVERSION} && \
	${SED} s,/usr/share/fonts/type1/gsfonts,${PREFIX}/share/ghostscript/fonts, \
	< gsfonts-fontmap.xml > ${DATADIR}/${DISTVERSION}/fontmap.xml

.include <bsd.port.mk>
