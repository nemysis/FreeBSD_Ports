# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD: head/graphics/libmng/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	libmng
PORTVERSION=	1.0.10
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION} \
		http://www.libmng.com/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiple-image Network Graphics (MNG) reference library

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

OPTIONS=	MNG_OPTIMIZE "Use vendor's new optimization flags" off

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	WITH_MNG_OPTIMIZE=${WITH_MNG_OPTIMIZE}
MAKE_JOBS_SAFE=	yes

USE_LDCONFIG=	yes

MAN3=		libmng.3
MAN5=		mng.5 jng.5

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN3} ${MAN3PREFIX}/man/man3 \
		&& ${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
