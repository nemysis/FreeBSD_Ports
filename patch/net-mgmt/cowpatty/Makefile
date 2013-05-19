# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD: head/net-mgmt/cowpatty/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	cowpatty
PORTVERSION=	4.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.willhackforsushi.com/code/${PORTNAME}/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Brute-force dictionary attack against WPA-PSK

PORTDOCS=	FAQ README
SUB_FILES=	pkg-message

USE_OPENSSL=	yes

PLIST_FILES=	bin/cowpatty bin/genpmk

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
