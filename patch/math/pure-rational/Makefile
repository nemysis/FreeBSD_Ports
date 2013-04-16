# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/math/pure-rational/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-rational
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	math
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Rational number library for the Pure language

LICENSE=	GPLv3

USES=		pure

PLIST_FILES=	lib/pure/rational.pure \
		lib/pure/rat_interval.pure

PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
