# $FreeBSD: head/multimedia/libav/Makefile 327319 2013-09-14 21:44:14Z mva $

PORTNAME=	libav
PORTVERSION=	9.9
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	https://libav.org/releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Realtime audio/video conversion library

LICENSE=	GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils \
		texi2html:${PORTSDIR}/textproc/texi2html \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeSerif.ttf:${PORTSDIR}/x11-fonts/freefont-ttf

USES=		gmake perl5 pkgconfig
WANT_SDL=	yes
USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix="${PREFIX}" --mandir="${PREFIX}/man" --incdir="${PREFIX}/include/${PORTNAME}" \
		--libdir="${PREFIX}/lib/${PORTNAME}" --shlibdir="${PREFIX}/lib/${PORTNAME}" --datadir="${DATADIR}" \
		--enable-gpl --enable-runtime-cpudetect --enable-avcodec --enable-avformat --enable-avutil \
		--enable-swscale --enable-avfilter --enable-avresample \
		--enable-pthreads --enable-network --enable-memalign-hack
ALL_TARGET=	all
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	avconv.1 avprobe.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS Changelog

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	APIchanges RELEASE_NOTES *.txt

OPTIONS_DEFINE=	ALSA AMR_NB AMR_WB BZIP2 CDIO DEBUG DOCS FAAC FDK_AAC \
		FREETYPE FREI0R GRAY GSM ILBC JACK LAME LIBBLURAY \
		LIBDC1394 OPENCV OPENJPEG OPTIMIZED_CFLAGS OPUS \
		PULSEAUDIO RTMP SDL SMALL SCHROEDINGER SPEEX THEORA \
		V4L VAAPI VDPAU VO_AACENC VO_AMRWBENC VORBIS VPX \
		X264 XVID X11GRAB ZLIB

OPTIONS_DEFAULT=	BZIP2 CDIO FREETYPE FREI0R OPENCV OPENJPEG SHARED \
			SCHROEDINGER OPENSSL OPUS RTMPSDL SPEEX THEORA \
			V4LVORBIS VPX 264 X11GRAB XVID ZLIB

OPTIONS_SINGLE=	SSL LIBRARIES
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_SINGLE_LIBRARIES=	STATIC SHARED

OPTIONS_SUB=	yes

STATIC_DESC=	Build static libraries, avserver (unmaintained)
SHARED_DESC=	Build shared libraries
SMALL_DESC=	Optimize for size instead of speed
GRAY_DESC=	Full grayscale support (slower color)
CPU_DETECTION_DESC=	Detect cpu capabilities at runtime (bigger binary)
X11GRAB_DESC=	X11 grabbing
LIBDC1394_DESC=	IIDC-1394 grabbing via libdc1394
FDK_AAC_DESC=	AAC encoding via libfdk-aac
ILBC_DESC=	iLBC en/decoding via libilbc
OPUS_DESC=	Opus decoding via libopus

ALSA_LIB_DEPENDS=		libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ON=		--enable-indev=alsa --enable-outdev=alsa
ALSA_CONFIGURE_OFF=		--disable-indev=alsa --disable-outdev=alsa

AMR_NB_LIB_DEPENDS=		libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb

AMR_WB_LIB_DEPENDS=		libopencore-amrwb.so:${PORTSDIR}/audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb
AMR_WB_LIB_DEPENDS=		libopencore-amrwb.so:${PORTSDIR}/audio/opencore-amr

BZIP2_CONFIGURE_ENABLE=		bzlib

CDIO_LIB_DEPENDS=		libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_ENABLE=		libcdio

DEBUG_CONFIGURE_ENABLE=		debug

DOCS_CONFIGURE_ENABLE=		doc

FAAC_LIB_DEPENDS=		libfaac.so:${PORTSDIR}/audio/faac
FAAC_CONFIGURE_ENABLE=		libfaac




STATIC_CONFIGURE_ENABLE=	static

SHARED_CONFIGURE_ENABLE=	shared

GNUTLS_CONFIGURE_ENABLE=	gnutls
GNUTLS_LIB_DEPEND=		libgnutls.so:${PORTSDIR}/security/gnutls

OPENSSL_CONFIGURE_ENABLE=	openssl

SMALL_CONFIGURE_ENABLE=		small

GRAY_CONFIGURE_ENABLE=		gray

X11GRAB_CONFIGURE_ENABLE=	x11grab

VAAPI_CONFIGURE_ENABLE=		vaapi
VAAPI_LIB_DEPENDS=		libva.so:${PORTSDIR}/multimedia/libva

VDPAU_CONFIGURE_ENABLE=		vdpau
VDPAU_LIB_DEPENDS=		libvdpau.so:${PORTSDIR}/multimedia/libvdpau

FREI0R_CONFIGURE_ENABLE=	frei0r
FREI0R_BUILD_DEPENDS=		${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r

LIBBLURAY_LIB_DEPENDS=		libbluray.so:${PORTSDIR}/multimedia/libbluray

LIBDC1394_CONFIGURE_ENABLE=	libdc1394
LIBDC1394_LIB_DEPENDS=		libdc1394.so:${PORTSDIR}/multimedia/libdc1394


FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_LIB_DEPENDS=		libfdk-aac.so:${PORTSDIR}/audio/fdk-aac

FREETYPE_CONFIGURE_ENABLE=	libfreetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2

GSM_CONFIGURE_ENABLE=		libgsm
GSM_LIB_DEPENDS=		libgsm.so:${PORTSDIR}/audio/gsm

ILBC_CONFIGURE_ENABLE=		libilbc
ILBC_BUILD_DEPENDS=		${LOCALBASE}/include/ilbc.h:${PORTSDIR}/net/libilbc

LAME_CONFIGURE_ENABLE=		libmp3lame
LAME_LIB_DEPENDS=		libmp3lame.so:${PORTSDIR}/audio/lame


OPENCV_CONFIGURE_ENABLE=	libopencv
OPENCV_LIB_DEPENDS=		libopencv_objdetect.so:${PORTSDIR}/graphics/opencv \
				libopencv_gpu.so:${PORTSDIR}/graphics/opencv

OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg
OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg

OPUS_CONFIGURE_ENABLE=		libopus
OPUS_LIB_DEPENDS=		libopus.so:${PORTSDIR}/audio/opus

PULSEAUDIO_CONFIGURE_ENABLE=	libpulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio

RTMP_CONFIGURE_ENABLE=		librtmp
RTMP_LIB_DEPENDS=		librtmp.so:${PORTSDIR}/multimedia/rtmpdump

SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger
SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger

SPEEX_CONFIGURE_ENABLE=		libspeex
SPEEX_LIB_DEPENDS=		libspeex.so:${PORTSDIR}/audio/speex

THEORA_CONFIGURE_ENABLE=	libtheora
THEORA_LIB_DEPENDS=		libtheora.so:${PORTSDIR}/multimedia/libtheora

VO_AACENC_CONFIGURE_ENABLE=	libvo-aacenc
VO_AACENC_LIB_DEPENDS=		libvo-aacenc.so:${PORTSDIR}/audio/vo-aacenc

VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc
VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:${PORTSDIR}/audio/vo-amrwbenc

VORBIS_CONFIGURE_ENABLE=	libvorbis
VORBIS_LIB_DEPENDS=		libvorbis.so:${PORTSDIR}/audio/libvorbis

SDL_CONFIGURE_ENABLE=		avplay

V4L_LIB_DEPENDS=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_CONFIGURE_ENABLE=		indev=v4l2

VPX_CONFIGURE_ENABLE=		libvpx
VPX_LIB_DEPENDS=		libvpx.so:${PORTSDIR}/multimedia/libvpx

X264_CONFIGURE_ENABLE=		libx264
X264_LIB_DEPENDS=		libx264.so:${PORTSDIR}/multimedia/x264

XVID_CONFIGURE_ENABLE=		libxvid
XVID_LIB_DEPENDS=		libxvidcore.so:${PORTSDIR}/multimedia/xvid

ZLIB_CONFIGURE_ENABLE=		zlib

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=		indev=jack



OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSTATIC}
USE_RC_SUBR=	avserver
MAN1+=		avserver.1
CONFIGURE_ARGS+=	--enable-avserver
.else
CONFIGURE_ARGS+=	--disable-avserver
.endif

.if ${PORT_OPTIONS:MOPENSSL}
LIBAV_NONFREE=	yes
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MX11GRAB}
USE_XORG=	x11 xext xfixes
.endif

.if ${PORT_OPTIONS:MFAAC}
LIBAV_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MFDK_AAC}
LIBAV_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MAMR_NB}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MAMR_WB}
GPL3=	yes
.endif

.if ! ${PORT_OPTIONS:MALSA}
CONFIGURE_ARGS+=	--disable-indev=alsa --disable-outdev=alsa
.endif

.if ${PORT_OPTIONS:MVO_AACENC}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MVO_AMRWBENC}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
MAN1+=		avplay.1
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

.if defined(GPL3)
CONFIGURE_ARGS+=	--enable-version3
LICENSE+=	GPLv3 LGPL3
.endif

.if defined(LIBAV_NONFREE)
CONFIGURE_ARGS+=	--enable-nonfree
RESTRICTED=	linking to libfaac restricts redistribution
.endif

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|$$(NAME).pc|$$(NAME)-${PORTNAME}.pc|g' \
		-e 's|install-lib$$(NAME)-pkgconfig|install-lib$$(NAME)-${PORTNAME}-pkgconfig|g' \
		${WRKSRC}/library.mak
	@${REINPLACE_CMD} -e 's|arch_default=$$(uname -m)|arch_default=$$(uname -p)|' \
		-e 's|-ldl||' \
		-e 's|gsm/gsm.h|gsm.h|' \
		-e 's|check_header linux/fb.h|#check_header linux/fb.h|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <SDL|#include <SDL/SDL|' \
		${WRKSRC}/avplay.c
	@${REINPLACE_CMD} -e 's|/etc/avserver.conf|${PREFIX}/etc/avserver.conf|' \
		${WRKSRC}/avserver.c
	@${FIND} ${WRKSRC}/doc -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/|${LOCALBASE}/lib/X11/fonts/freefont-ttf/|g'
	@${REINPLACE_CMD} -e 's|install-progs-$$(CONFIG_DOC)|#install-progs-$$(CONFIG_DOC)|' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/perl -w|${PERL}|' \
		${WRKSRC}/doc/texi2pod.pl
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/libavcodec/libgsm.c

.if ! ${PORT_OPTIONS:MV4L}
	@${REINPLACE_CMD} -i '' '/check_header linux/videodev2.h/,/check_struct linux/videodev2.h/s/^/#/' \
		${WRKSRC}/configure
.endif

post-configure:
.for d in libavcodec libavdevice libavfilter libavformat libavresample libavutil libswscale
	@(cd ${WRKSRC}/${d} ; ${CP} -a ${d}.pc ${d}-${PORTNAME}.pc)
.endfor

post-install:
.if ${PORT_OPTIONS:MSTATIC}
	${INSTALL_DATA} ${WRKSRC}/doc/avserver.conf ${PREFIX}/etc/avserver.conf.sample
	@[ -f ${PREFIX}/etc/avserver.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/doc/avserver.conf ${PREFIX}/etc/avserver.conf
.endif

	(cd ${WRKSRC}/doc ; ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.post.mk>
