# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD: head/net/pathneck/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	pathneck
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.cmu.edu/~hnn/pathneck/ \
		http://gs274.sp.cs.cmu.edu/www/pathneck/ \
		http://www.unixified.net/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Active network path probing tool

LICENSE=	GPLv2

MAKEFILE=	Makefile.bsd

PLIST_FILES=	sbin/pathneck \
		sbin/get-choke

PORTDOCS=	ChangeLog README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^CC .=|CC ?=|' \
		-e 's|^CFLAGS .=|CFLAGS +=|' \
		${WRKSRC}/Makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathneck ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/get-choke ${PREFIX}/sbin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
