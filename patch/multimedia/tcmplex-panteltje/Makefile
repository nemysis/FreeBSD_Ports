# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD: head/multimedia/tcmplex-panteltje/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	tcmplex-panteltje
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://panteltje.com/panteltje/dvd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	a.out

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
