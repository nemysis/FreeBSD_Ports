# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD: head/net/pchar/Makefile 305676 2012-10-10 17:44:07Z tabthorpe $

PORTNAME=	pchar
PORTVERSION=	1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.kitchenlab.org/www/bmah/Software/pchar/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bmah

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sandia Internet path characterization tool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcap

PLIST_FILES=	sbin/${PORTNAME}

MAN8=		pchar.8

PORTDOCS=	CHANGES FAQ README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
