# Created by: Jerry A! <jerry@thehutt.org>
# $FreeBSD: head/net-mgmt/ap-utils/Makefile 317503 2013-05-06 10:22:41Z bapt $

PORTNAME=	ap-utils
PORTVERSION=	1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://linux.zhitomir.net/ap-utils/

MAINTAINER=	david@catwhisker.org
COMMENT=	Set of utilities to configure and monitor wireless access points

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		iconv
GNU_CONFIGURE=	yes

MAN8=		ap-auth.8 ap-config.8 ap-gl.8 ap-mrtg.8 ap-tftp.8 ap-trapd.8

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README THANKS TODO

DOCSRCDIR2=	${WRKSRC}/Documentation
DOCSDIR2=	${DOCSDIR}/Documentation
DOC_FILES2=	FAQ HARDWARE-NOTES Ovislink-HOWTO.html

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|g' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
