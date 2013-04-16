# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/textproc/pure-csv/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	pure-csv
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	textproc
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	CSV reading and writing module for the Pure language

LICENSE=	BSD

USES=		pure

PLIST_FILES=	lib/pure/csv.pure \
		lib/pure/csv.so

PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
