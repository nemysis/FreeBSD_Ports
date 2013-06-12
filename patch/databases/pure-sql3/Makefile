# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/databases/pure-sql3/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-sql3
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	databases
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language binding to the SQLite3 library

LICENSE=	BSD

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

USES=		pure

PLIST_FILES=	lib/pure/sql3.pure \
		lib/pure/sql3util.so

PORTDOCS=	README

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
