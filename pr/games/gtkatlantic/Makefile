# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/games/gtkatlantic/Makefile 300896 2012-07-14 13:54:48Z beat $
#    $MCom: ports-stable/games/gtkatlantic/Makefile,v 1.1 2006/03/04 21:36:29 ahze Exp $

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/${PORTNAME}/downloads/v0.4/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game like Monopoly(tm)

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="GtkAtlantic" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -Werror||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mkdir |$$(mkdir_p) |g' ${WRKSRC}/Makefile.in

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
