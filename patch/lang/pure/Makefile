# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: nemysis/lang/pure/Makefile 10924 2013-04-05 16:23:34Z nemysis $

PORTNAME=	pure
PORTVERSION=	0.57
CATEGORIES=	lang
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-docs-${PORTVERSION}.tar.gz
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Modern-style functional programming language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpfr:${PORTSDIR}/math/mpfr
BUILD_DEPENDS=	llvm>=0:${PORTSDIR}/devel/llvm
RUN_DEPENDS=	llvm>=0:${PORTSDIR}/devel/llvm

MAN1=		pure.1
SUB_FILES=	pkg-message

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libgmp-prefix=${LOCALBASE} --enable-release
USES=		pure pathfix pkgconfig
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	EMACS ETC

EMACS_DESC=	Compile pure-mode.el with Emacs
ETC_DESC=	Copy Pure syntax highlighting to ${DATADIR}/etc

OPTIONS_DEFAULT=	ETC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
USE_EMACS=	yes
MAKE_ARGS+=	emacs_prefix=${PREFIX}
PLIST_SUB+=	ELC=""
.else
CONFIGURE_ARGS+=	--without-elisp
PLIST_SUB+=	ELC="@comment "
.endif

.if ${PORT_OPTIONS:METC}
PLIST_SUB+=	ETC=""
.else
PLIST_SUB+=	ETC="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

.if ${OSVERSION} < 900014
SUB_LIST+=	NOCLANG=""
.else
SUB_LIST+=	NOCLANG="@comment "
.endif

# automatically disable readline support if editline support is available
.if exists(/usr/include/edit/readline/readline.h)
CONFIGURE_ARGS+=	--without-readline
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd
.endif

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:METC}
	@${MKDIR} ${DATADIR}/etc
	@(cd ${WRKSRC} && ${RM} -f etc/*.in && ${COPYTREE_SHARE} etc/ ${DATADIR})
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION} && ${RM} -f Makefile && ${COPYTREE_SHARE} . ${DOCSDIR})
	${LN} -sf ${DOCSDIR} ${PREFIX}/lib/${PORTNAME}/docs
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:METC}
	@${ECHO_CMD}
	@${ECHO_CMD}
	@${ECHO_CMD} "==============================================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "	Note that we installed a few Pure syntax highlighting"
	@${ECHO_CMD} "	files for the code editors in ${DATADIR}/etc/"
	@${ECHO_CMD}
	@${ECHO_CMD} "==============================================================================="
	@${ECHO_CMD}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
