# Created by: Frank Laszlo <laszlof@freebsdmatrix.net>
# $FreeBSD: head/games/euchre/Makefile 315255 2013-03-26 04:32:02Z miwi $

PORTNAME=	euchre
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very popular card game with variable skill levels

LICENSE=	GPLv2

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/euchre

PORTDOCS=	AUTHORS ChangeLog README TODO

DESKTOP_ENTRIES="Euchre" "" "" "${PORTNAME}" "" true

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^AM_/s|-Werror||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|int)|long int)|g' \
		${WRKSRC}/src/gui/callbacks.cpp ${WRKSRC}/src/lib/Game.cpp

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
