# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD: head/net/xmlrpc-epi/Makefile 316662 2013-04-27 11:59:28Z mva $

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.54.2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-base/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose implementation of the xmlrpc specification in C

LICENSE=	MIT

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
USES=		iconv
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ARGS=	--program-transform="s|^|xre-|"

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean \
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-0.* xmlrpc-c-devel-[0-9]*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

regression-test:
.for tm in ${METHODS}
	cd ${WRKSRC}/sample && ./sample -method method_${tm}
.endfor

.include <bsd.port.mk>
