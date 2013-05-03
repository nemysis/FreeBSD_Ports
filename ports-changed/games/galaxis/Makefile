# Created by: Andrey Zakhvatov
# $FreeBSD: ports/games/galaxis/Makefile,v 1.20 2012/09/07 23:35:52 amdmi3 Exp $

PORTNAME=	galaxis
PORTVERSION=	1.8
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/galaxis/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Clone of the nifty little Macintosh game

LICENSE=	BSD

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNDEBUG"
ALL_TARGET=	${PORTNAME}
USE_GMAKE=	yes

MAN6=		${PORTNAME}.6
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
