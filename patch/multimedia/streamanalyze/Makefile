# Created by: Heiner Eichmann
# $FreeBSD: head/multimedia/streamanalyze/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	streamanalyze
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	CENKES LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shrink-factor calculator for StreamDVD

LIB_DEPENDS=	dvdread:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/StreamAnalyze

PLIST_FILES=	bin/streamanalyze
PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -g -Wall|${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/#include <getopt\.h>/ d' ${WRKSRC}/streamanalyze.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamanalyze ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
