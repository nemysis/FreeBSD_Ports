# Created by: ijliao
# $FreeBSD: head/devel/dparser/Makefile 325391 2013-08-26 12:21:32Z gahr $

PORTNAME=	dparser
PORTVERSION=	1.30
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	d-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple but powerful tool for parsing

OPTIONS_DEFINE=	BOEHM DOCS
BOEHM_DESC=	Boehm garbage collector support

OPTIONS_SUB=	yes

BOEHM_LIB_DEPENDS=	libgc.so:${PORTSDIR}/devel/boehm-gc

WRKSRC=		${WRKDIR}/d

EXTRACT_AFTER_ARGS=	--exclude "*my*"
USES=		gmake
MAKE_ARGS=	CC="${CC}" D_OPTIMIZE= PREFIX=${PREFIX}

MAN1=		make_dparser.1
PORTDOCS=	*
PLIST_FILES=	bin/make_dparser include/dparse.h include/dparse_tables.h \
		include/dparse_tree.h include/dsymtab.h lib/${LIBDPARSE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOEHM}
MAKE_ARGS+=	D_USE_GC=1 \
		GC_CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"
LIBDPARSE=	libdparse_gc.a
.else
LIBDPARSE=	libdparse.a
.endif

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_dparser ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.for f in dparse.h dparse_tables.h dparse_tree.h dsymtab.h
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${PREFIX}/include)
.endfor
	${INSTALL_DATA} ${WRKSRC}/${LIBDPARSE} ${PREFIX}/lib/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
