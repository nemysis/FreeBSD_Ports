# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	bumblebee
PORTVERSION=	3.0.2
CATEGORIES=	x11
MASTER_SITES=	GH

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Bumblebee daemon for Optimus hybrid graphics chipsets

LICENSE=	GPLv3

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver

USE_GITHUB=	yes
GH_ACCOUNT=	seanbruno
GH_PROJECT=	fbsd-bumblebee
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	48a1491

USE_GNOME=	glib20
USE_XORG=	x11
USE_GL=		gl
USES=		pkgconfig
USE_RC_SUBR=	bumblebeed

USE_AUTOTOOLS=	aclocal:env automake:env autoheader:env autoconf:env
AUTOMAKE_ARGS=	--add-missing --force
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CONF_DRIVER=nvidia CONF_DRIVER_MODULE_NVIDIA=nvidia \
			CONF_LDPATH_NVIDIA=${PREFIX}/lib:/compat/linux/usr/lib \
			CONF_MODPATH_NVIDIA=${PREFIX}/lib/xorg/modules/extensions/.nvidia,${PREFIX}/lib/xorg/modules/

MAN1=		bumblebeed.1 optirun.1
PORTDOCS=	*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	BASH

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
PLIST_SUB+=	BASH=""
.else
PLIST_SUB+=	BASH="@comment "
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -fi)

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s|$$(relnotes) README.markdown||g' ${WRKSRC}/Makefile.am
.endif

.if${PORT_OPTIONS:MBASH}
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
.endif

.if ! ${PORT_OPTIONS:MBASH}
	@${REINPLACE_CMD} -e 's|scripts/bash_completion/bumblebee||' \
		-e 's|completiondir|#completiondir|' \
		-e 's|completion_DATA|#completion_DATA|'\
		${WRKSRC}/Makefile.am
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
