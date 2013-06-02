# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD: head/net/tcpstat/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	tcpstat
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	http://www.frenchfries.net/paul/tcpstat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to report various network statistics

LICENSE=	BSD

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tcpstat bin/tcpprof

MAN1=		tcpstat.1 tcpprof.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	Tips_and_Tricks.txt

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
