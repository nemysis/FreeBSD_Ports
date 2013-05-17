# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	edgar
PORTVERSION=	1.08.1
CATEGORIES=	games
MASTER_SITES=	SF/legendof${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.1/-1/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	2D platform game with a persistent world

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/.1//}

USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf
WITH_ZLIB=	yes
MAKEFILE=	makefile

PORTDOCS=	*

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
	-e 's|$(DESTDIR)/usr|${LOCALBASE}|' \
	-e 's|/games/|/bin/|' \
	-e 's|/share/bin/edgar/|/share/edgar/|' \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|SDL/SDL|${LOCALBASE}/include/SDL/SDL|g' ${WRKSRC}/src/headers.h

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' -e '/DOC_DIR/d' ${WRKSRC}/makefile
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' -e '/LOCALE_MO =/d' ${WRKSRC}/makefile
.endif

do-build:
	@(cd ${WRKSRC} && ${GMAKE})

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
