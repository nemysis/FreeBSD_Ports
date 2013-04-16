# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD: head/graphics/grads/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	grads
PORTVERSION=	2.0.2
CATEGORIES=	graphics science math
MASTER_SITES=	ftp://cola.gmu.edu/grads/2.0/:src \
		ftp://cola.gmu.edu/grads/:other
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}:src \
		example.tar.gz:other
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	The Grid Analysis and Display System

BUILD_DEPENDS=	${LOCALBASE}/lib/libudunits2.a:${PORTSDIR}/science/udunits \
		${LOCALBASE}/lib/libsx.a:${PORTSDIR}/x11/libsx
LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SUPPLIBS="${LOCALBASE}"
CONFIGURE_ARGS+=	--enable-dyn-supplibs \
			--with-readline \
			--with-printim \
			--with-gui \
			--with-x

OPTIONS_DEFINE=	HDF NETCDF
HDF_DESC=	Build hdf-support (only hdf OR netcdf is supported
NETCDF_DESC=	Build netcdf-support
OPTIONS_DEFAULT=	HDF

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHDF}
#.if defined(WITH_HDF)
LIB_DEPENDS+=		mfhdf.3:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=	--with-hdf
PLIST_SUB+=		NETCDF="@comment " HDF=""
#.else
#PLIST_SUB+=		NETCDF="@comment "
.endif

.if ${PORT_OPTIONS:MNETCDF}
#.if defined(WITH_NETCDF)
LIB_DEPENDS+=		netcdf:${PORTSDIR}/science/netcdf4
CONFIGURE_ARGS+=	--with-nc
PLIST_SUB+=		NETCDF="" HDF="@comment "
.endif

post-extract:
	${MKDIR} "${WRKSRC}/examples"
	cd "${WRKSRC}/examples" && ${TAR} -xzf "${_DISTDIR}/example.tar.gz"

post-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/src/gx.h
	${REINPLACE_CMD} -e "s:ludunits:ludunits2:" ${WRKSRC}/src/Makefile

post-install:
	${MKDIR} "${DATADIR}"
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR})

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} "${EXAMPLESDIR}"
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} "${DOCSDIR}"
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
